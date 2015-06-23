(function($) {
Drupal.behaviors.hrDatasets = {
  attach: function (context, settings) {

  Dataset = Backbone.Model.extend({
    defaults: {
      title: '',
      url: '',
    },
  });

  DatasetsList = Backbone.Collection.extend({
    model: Dataset,
    params: {},
    url: function() {
      return 'https://data.hdx.rwlabs.org/api/3/action/package_search?q=uga&rows=' + this.limit + '&start=' + this.skip;
    },

    parse: function(response) {
      var models = response.result.results ? response.result.results : {};
      this.count = response.result.count;
      var fields = [];
      _.each(models, function(resource){
        fields.push({title: resource.name, url: 'https://data.hdx.rwlabs.org/dataset/' + resource.id});
      });
      return fields;
      },

      limit: 10,
      skip: 0,
      count: 0,

    });

    DatasetView = Backbone.View.extend({

      router: null,

      clear: function() {
        this.$el.empty();
      },

      loading: function() {
        this.hide();
        $('#loading').show();
      },

      finishedLoading: function() {
        $('#loading').hide();
        this.show();
      },

    });

    DatasetTableView = DatasetView.extend({

        numItems: 10,
        currentPage: 1,

        initialize: function() {
            this.DatasetsList = new DatasetsList;
            this.DatasetsList.limit = this.numItems;
        },

        loadResults: function() {
          var that = this;
          this.DatasetsList.fetch({
            success: function (fields) {
              var template = _.template($('#hdx_datasets_list_view').html());
              $('#datasets-list-table tbody').append(template({fields: fields.models}));
              that.finishedLoading();
            },
          });
        },

        page: function(page) {
          this.loading();
          this.currentPage = page;
          this.clear();
          this.DatasetsList.skip = this.numItems * (page - 1);
          this.loadResults();
        },

        render: function (model){
          this.loadResults();
        },

        clear: function() {
          $('#datasets-list-table tbody').empty();
        },

        show: function() {
          $('#datasets-list').show();
          $('#block-hr-datasets-hr-datasets-filters').show();
        },

        hide: function() {
          $('#datasets-list').hide();
          $('#block-hr-datasets-hr-datasets-filters').hide();
        },

        finishedLoading: function() {
          $('#loading').hide();
          this.show();
          $('.facetapi-active').html(this.DatasetsList.count + ' items');
          this.pager();
        },

        pager: function() {
          var nextPage = parseInt(this.currentPage) + 1;
          var previousPage = parseInt(this.currentPage) - 1;
          var count = this.DatasetsList.count;
          var itemsPerPage = this.numItems;
          var paramsString = $.param(this.DatasetsList.params);
          if (paramsString != '') {
            paramsString = '?' + paramsString;
          }
          if (this.currentPage * itemsPerPage < count) {
            $('#next').attr('href', '#table/' + nextPage + paramsString);
          }
          else {
            $('#next').attr('href', '#table/' + this.currentPage + paramsString);
          }
          if (previousPage > 0) {
            $('#previous').attr('href', '#table/' + previousPage + paramsString);
          }
          else {
            $('#previous').attr('href', '#table/' + this.currentPage + paramsString);
          }
        },
    });

    DatasetsRouter = Backbone.Router.extend({
      routes: {
        "table/:page" : "table",
        "*actions": "defaultRoute",
      },

      tableView: new DatasetTableView({el: 'body'}),

      initialize: function() {
        this.tableView.router = this;
      },

      defaultRoute: function (actions) {
        this.navigate('table/1', {trigger: true});
      },

      table: function(page) {
        this.tableView.page(page);
      },

      navigateWithParams: function(url, params) {
        this.navigate(url + '?' + $.param(params), {trigger: true});
      },
    });
    var datasets_router = new DatasetsRouter;

    Backbone.history.start();

  }
}
})(jQuery);
